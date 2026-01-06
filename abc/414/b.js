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
    
    let lenC = 0;
    let resultS = '';
    for(let i=1; i<=n; i++){
        const [c, l] = input[i].split(' ');
        //console.log(c, l);
        if(l.length > 3){
            console.log('Too Long');
            return;
        }
        const intL = Number(l);
        if(lenC+intL > 100){
            console.log('Too Long');
            return;
        }
        resultS += c.repeat(intL);
        lenC += intL;
    }
    console.log(resultS);
});