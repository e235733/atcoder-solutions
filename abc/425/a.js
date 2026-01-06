'use strict';
const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs.readFileSync(filePath, 'utf8').trim();

const n = Number(input);
let sum = 0;

for (let i = 1; i <= n; i++) {
  sum += (-1) ** i * i ** 3;
}

console.log(sum);