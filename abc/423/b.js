'use strict';
const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs.readFileSync(filePath, 'utf8').trim().split('\n');

const n = Number(input[0]);
const L = input[1].split(' ').map(Number);

let i = 0;

while(L[i] === 0 && i < n){
    i += 1;
}

if(i === n){
    console.log(0);
}
else{
    let j = n-1;
    while(L[j] === 0 && j > i){
        j -= 1;
    }
    if(i === j){
        console.log(0);
    }
    else{
        console.log(j-i);
    }
}