'use strict';
const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs.readFileSync(filePath, 'utf8').trim().split('\n');

const [n, m, k] = input[0].split(' ').map(Number);

const scores = new Array(n+1).fill(0);
const crear = [];

for(let i=1; i<=k; i++){
    const [a, _] = input[i].split(' ').map(Number);
    scores[a] += 1;
    if(scores[a] == m){
        crear.push(a);
    }
}
console.log(crear.join(' '));