"use strict";

function getRandomArbitrary(min, max) {
  return Math.random() * (max - min) + min;
}

let n = process.argv[2];
console.log(n);

for (let i = 0; i < n; i++) {
    console.log(getRandomArbitrary(-1000000, 1000001) + ' ' + getRandomArbitrary(-1000000, 1000001));
}
