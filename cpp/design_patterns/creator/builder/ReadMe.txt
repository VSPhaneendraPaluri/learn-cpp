## Important Notes on Builder Pattern

- Is useful when developer wants to avoid bit long parameterized constructors
- Is a very good pattern for creating similar objects which differ only in traits but the build steps remain the same
- The director class is usually optional but is recommended to have one so the client application just need to call the required method for building an object
- This can internally put other patterns to work while creation of the objects
