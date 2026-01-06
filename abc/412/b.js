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
    const S = input[0];
    const T = input[1];

    for(let i=1; i<S.length; i++){
        if(S[i] === S[i].toUpperCase()){
            //console.log(S[i]);
            if(!T.includes(S[i-1])){
                console.log('No');
                return;
            }
        }
    }
    console.log('Yes');
});