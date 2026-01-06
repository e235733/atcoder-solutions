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
    const s = input[1];
    const tale = s[n-3]+s[n-2]+s[n-1];
    if(n >= 3){
        if(tale === 'tea'){
            console.log('Yes');
        }
        else{
            console.log('No');
        }
    }
    else{
        console.log('No');
    }
});