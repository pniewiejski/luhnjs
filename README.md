# luhnjs
**Luhn's algorithm**, also known as *mod 10 algorithm* is a simple checksum algorithm used widely
for securing/ validating identification numbers, such as credit card number. 💰💳
Check out [Wikipedia](https://en.wikipedia.org/wiki/Luhn_algorithm) for more information. 

## ymmm... but why? 
The main goal for this project was to simply play with the [N-API](https://nodejs.org/dist/latest-v12.x/docs/api/n-api.html#n_api_n_api) addon capability, 
implement some algorithm in C++ and use it in node.js application. 👨‍💻 

Also, ...*just for fun* 🤷‍♂️ 
![](https://media1.giphy.com/media/xT1XH0FX2Mo4AVrPFe/giphy.gifcid=790b76112a16582941fae9fe8b03446705491f0722c5b1df&amp;rid=giphy.gif)

## How do I use it? 
You can check if provided number (actually a *string* 🤫) is *"valid"* 
according to the Luhn's algorithm. 
```js
const luhn = require("luhnjs");
const isValid = luhn.isValid("123");
console.log(isValid);
```
You can also generate a checkDigit. Let's take an example from Wikipedia: 
*Assume an example of an account number "7992739871" that will have a check digit added, making it of the form 7992739871x*. The way it works is that you should provide the `7992739871` number and the algorithm will compute the `x` digit. 
```js
const luhn = require("luhnjs");
const checkDigit = luhn.generateCheckDigit("7992739871");
console.log(checkDigit);
```

## How to build it? 
Please find scripts in `package.json`: 
* `npm run build` - This command will build the C++ project.
* `npm run clean`
If you want to find out how to run the C++ unit tests please read [this](./luhncpp/README.md).

## Sources 📚:
* [N-API docs](https://nodejs.github.io/node-addon-api/index.html)
* [node-gyp](https://github.com/nodejs/node-gyp)
* [googletest](https://github.com/google/googletest)
* [node-addon-api](https://github.com/nodejs/node-addon-api)
* [Beginners guide to writing NodeJS Addons using C++ and N-API (node-addon-api)](https://medium.com/@atulanand94/beginners-guide-to-writing-nodejs-addons-using-c-and-n-api-node-addon-api-9b3b718a9a7f)