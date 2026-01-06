'use strict';
const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs.readFileSync(filePath, 'utf8').trim().split('\n');

const [x, c] = input[0].split(' ').map(Number);
console.log(Math.floor(x / (1000 + c)) * 1000);