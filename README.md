ElasticMeow.stemmer.snowball
=========================

This is a fork of the [original snowball repo](https://github.com/snowballstem/snowball) where the snowball stemmer (english only) is compiled into [Javascript asm](http://asmjs.org/) with [Emscripten](https://github.com/kripken/emscripten) for use in the browser.

## Bower
For purely front-end work, you can use bower to get the js file.
```
bower install --save e2fyi/Snowball
```

## QuickStart
The main js file is located at `/emscripten/build/snowball_en.js`. You will need to load this script and run the module `Snowball`.
```html
<script src="./emscripten/build/snowball_en.js"></script>
```
```js
// init the module
Snowball();
```

The stemmer is available under the function `ElasticMeow.stemmer.snowball`. In order to reduce overheads, the stemmer can take in either a **space separated string of words** or an **array of words**, instead of a single word.

The stemmer return an output of the same type as the input (i.e. `String[]` will return `String[]`, `String` will return `String`).

**Space-separated strings**  
```js
// stem a whitespace separated string .
// return a string of whitespace separated string.
var stemmed = ElasticMeow.stemmer.snowball('happy going swimming');
// outputs 'happi go swim'
console.log(stemmed);
```

**Array of strings**
```js
// stem an array of words and return an array of stemmed words.
var stemmed = ElasticMeow.stemmer.snowball(['happy', 'going', 'swimming']);
// outputs ['happi', 'go', 'swim']
console.log(stemmed);
```

## Build
You will need to install [Emscripten and all the dependencies](http://kripken.github.io/emscripten-site/docs/getting_started/downloads.html).

Then you need to make `libstemmer` and various source files.
```
make
```

Then to compile the module.
```
emcc emscripten/snowball_en.c runtime/api.c runtime/utilities.c libstemmer/libstemmer.c src_c/stem_ISO_8859_1_english.c src_c/stem_UTF_8_english.c  --post-js emscripten/snowball.js --memory-init-file 0 -o emscripten/build/snowball_en.js -s MODULARIZE=1 -s EXPORT_NAME="'Snowball'" -O3
```  

or

```
npm run build
```

## Links
[http://snowballstem.org](http://snowballstem.org)
[http://emscripten.org](http://emscripten.org)
