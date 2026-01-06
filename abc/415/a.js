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
    const n = Number(input[0]);
    const A = input[1].split(' ').map(Number);
    const b = Number(input[2]);
    if(A.includes(b)){
        console.log('Yes');
    }
    else{
        console.log('No');
    }
});