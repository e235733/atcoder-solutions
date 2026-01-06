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

    //前の文字が'#'で、次に'.'が来たらそれを'o'に置換する
    let T = '';
    let beforeS = '#';
    for(let i=0; i<S.length; i++){
        if(beforeS === '#' && S[i] === '.'){
            T += 'o';
        }
        else{
            T += S[i];
        }
        beforeS = S[i];
    }

    console.log(T);
});