## Some Important Notes on Singleton Pattern

- Very popular design pattern in use by the developers
- Only one instance is created and the same instance is provided on every access
- Singleton class gets initialized for the first time it is called
- Use it if one requires stricter control over global variables


## Notes
- Violates the Single Responsiblity Principle
- Is not multi-thread safe.  Special care to be taken in a multi-threaded environment
- Testability of a singleton class is poor, comes with lots of drawbacks
