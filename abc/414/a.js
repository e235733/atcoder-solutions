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
    const [n, l, r] = input[0].split(' ').map(Number);
    let sumListner = 0;
    for(let i=1; i<n+1; i++){
        const [x, y] = input[i].split(' ').map(Number);
        if(x <= l && y >= r){
            sumListner += 1;
        }
    }
    console.log(sumListner);
});