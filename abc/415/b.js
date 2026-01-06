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
    const size = S.length;

    let plot = 0;
    while(plot < size-1){
        let indexLug1;
        let indexLug2;
        //最初の荷物がある区画を特定する
        while(S[plot] === '.' && plot < size){
            plot += 1;
        }
        indexLug1 = plot;
        plot += 1;
        //2個目の荷物がある区画を特定する
        while(S[plot] === '.' && plot < size){
            plot += 1;
        }
        indexLug2 = plot;
        plot += 1;
        console.log([indexLug1+1, indexLug2+1].join(','));
    }
});