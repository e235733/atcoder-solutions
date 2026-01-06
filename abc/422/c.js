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
    const t = Number(input[0]);
    for(let i=1; i<=t; i++){
        const [a, b, c] = input[i].split(' ').map(Number);
        //console.log(a, b, c);
        const sumChars = a + b + c;
        const numMinAOrC = Math.min(a, c);
        //numMinAOrCの3倍がsumChars以下なら、numMinAOrCが答え
        if(numMinAOrC*3 <= sumChars){
            console.log(numMinAOrC);
        }
        //そうでなければsumCharsの1/3の小数点以下切り捨てが答え
        else{
            console.log(Math.floor(sumChars/3));
        }
    }
});