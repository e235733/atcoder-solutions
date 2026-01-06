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
    const dic = {'red':'SSS', 'blue':'FFF', 'green':'MMM'};
    const s = input[0];

    if(Object.keys(dic).includes(s)){
        console.log(dic[s]);
    }
    else{
        console.log('Unknown');
    }
});