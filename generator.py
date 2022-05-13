import argparse
from distutils.dir_util import remove_tree
import logging
from os import chdir, system
from pathlib import Path


class ArgumentParser(object):
    verbosity_levels = ['DEBUG', 'INFO', 'WARNING', 'ERROR', 'CRITICAL']
    values = ['yes', 'no']
    build_types = ['Release', 'Debug']

    def __init__(self) -> None:
        self.__parser = argparse.ArgumentParser('Hex Build System Generator')
        self._add_arguments()
        self.__cli = vars(self.__parser.parse_args())

    def _add_arguments(self) -> None:
        self.__parser.add_argument('-b', '--build', help="Build the solution", required=True,
                                   default=ArgumentParser.values[1], choices=ArgumentParser.values)
        self.__parser.add_argument('-c', '--create', help="Create the solution", required=True,
                                   default=ArgumentParser.values[1], choices=ArgumentParser.values)
        self.__parser.add_argument('-d', '--delete', help="Delete the solution", required=False,
                                   default=ArgumentParser.values[1], choices=ArgumentParser.values)
        self.__parser.add_argument('-r', '--run', help="Run the solution", required=True,
                                   default=ArgumentParser.values[1], choices=ArgumentParser.values)
        self.__parser.add_argument('-t', '--build_type', help="Select the build type from the choices", required=True,
                                   default=ArgumentParser.build_types[0], choices=ArgumentParser.build_types)
        self.__parser.add_argument('-v', '--verbosity_level', help="Select the verbosity level", required=False,
                                   default=ArgumentParser.verbosity_levels[3], choices=ArgumentParser.verbosity_levels)

    def get_build(self) -> str:
        return self.__cli.get('build')

    def get_create(self) -> str:
        return self.__cli.get("create")

    def get_delete(self) -> str:
	    return self.__cli.get("delete")

    def get_run(self) -> str:
        return self.__cli.get("run")
		
    def get_build_type(self) -> str:
        return self.__cli.get("build_type")

    def get_verbosity_level(self) -> int:
        logging_levels = {
            'DEBUG': logging.DEBUG,
            'INFO': logging.INFO,
            'WARNING': logging.WARNING,
            'ERROR': logging.ERROR,
            'CRITICAL': logging.CRITICAL
        }
        return logging_levels[self.__cli.get('verbosity_level')]


class BinaryDecoderProject(object):

    def __init__(self, build_type: str) -> None:
        self.__logger = logging.getLogger(__name__)
        self.__cwd = Path.cwd()
        self.__build_dir = self.__cwd.joinpath('build')
        self.__generator = 'Visual Studio 16 2019'
        self.__build_type = build_type

    def delete_solution(self) -> None:
	    if self.__build_dir.exists():
		    remove_tree(str(self.__build_dir))

    def create_build_directory(self) -> None:
        if self.__build_dir.exists():
            self.__logger.info(f'Removing build directory: {self.__build_dir}')
            remove_tree(str(self.__build_dir))
        self.__logger.info(f'Creating build directory: {self.__build_dir}')
        self.__build_dir.mkdir()

    def create_solution(self) -> None:
        self.create_build_directory()
        cmake_command = f'cmake -G "{self.__generator}" -B {self.__build_dir} -DCMAKE_BUILD_TYPE={self.__build_type}'
        self.__logger.info(f'cmake_command: {cmake_command}')
        system(cmake_command)

    def build_solution(self) -> None:
        self.create_solution()
        cmake_command = f'cmake --build {self.__build_dir} --config {self.__build_type}'
        self.__logger.info(f'cmake_command: {cmake_command}')
        system(cmake_command)

    def run_tests(self) -> None:
        cmake_command = "ctest -C {self.__build_type}"
        self.__logger.info(f'cmake_command: {cmake_command}')
        system(cmake_command)


def main():
    ap = ArgumentParser()
    logger = logging.getLogger(__name__)

    # Set logger properties
    logging.basicConfig()
    logging.root.setLevel(ap.get_verbosity_level())

    binary_decoder = BinaryDecoderProject(ap.get_build_type())

    if ap.get_delete() == 'yes':
	    binary_decoder.delete_solution()

    if ap.get_build() == 'yes':
        binary_decoder.build_solution()
    else:
        if ap.get_create() == 'yes':
            binary_decoder.create_solution()

    if ap.get_run() == 'yes':
        if ap.get_build() == 'no':
            logging.warn(f'Kindly first create and build the solution')
        else:
            binary_decoder.run_tests()


if __name__ == "__main__":
    main()