## Some Important Notes on Factory Pattern

- Inheritance is the backbone
- This design pattern lets the developer create the support for new product type without disturbing the client code
- This becomes possible as all the products implement a common product interface
- It's the responsibility of the creator class to correctly construct & return the required product variant to the client (caller)
- The client code just queries for the product using the product interface methods

## Features
- Use it when the user doesn't know the product type beforehand
- When the developer needs to extend the product library support for new products with minimal changes (inheritance makes it easy)
- To re-use created products instead of re-creating them again
