'use strict';

const fs = require('fs');
const readline = require('readline');

const isAtCoder = process.platform === 'linux';

const inputStream = isAtCoder
  ? process.stdin
  : fs.createReadStream('./input.txt');

const rl = readline.createInterface({
  input: inputStream,
});

const input = [];
rl.on('line', (line) => {
  input.push(line);
});

rl.on('close', () => {
    const [i, j] = input[0].split('-').map(Number);
    //console.log(i, j)
    let next_i;
    let next_j;
    if(j === 8){
        next_i = i + 1
        next_j = 1
    }
    else{
        next_i = i
        next_j = j + 1
    }
    console.log(next_i+'-'+next_j)
});