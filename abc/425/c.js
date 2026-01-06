'use strict';
const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs.readFileSync(filePath, 'utf8').split('\n');

const nums = input[0].split(' ').map(Number);
const n = nums[0];
const q = nums[1];
const A = input[1].split(' ').map((n) => Number(n));

const preSum = new Array(n+1).fill(0);
for(let i=1; i<=n; i++){
    preSum[i] = preSum[i-1] + A[i-1];
}
//console.log(preSum);

let head = 0;
for(let nextInputLine=2; nextInputLine<q+2; nextInputLine++){
    //console.log('A:'+A+', head'+head)
    const line = input[nextInputLine].split(' ').map(Number);
    if(line[0] === 1){
        const c = line[1];
        const move = c % n;
        if(head + move > n - 1){
            head = head + move - n;
        }
        else{
            head += move
        }
    }
    else{
        let l = head + line[1] - 1;
        let r = head + line[2] - 1;
        if(l >= n){
            l -= n;
            r -= n;
            console.log(preSum[r+1] - preSum[l]);
            /*
            let sum = 0;
            for(l; l <= r; l++){
                sum += A[l];
            }
            console.log(sum);
            */
        }
        else if(r < n){
            console.log(preSum[r+1] - preSum[l]);
            let sum = 0;
            /*
            for(l; l <= r; l++){
                sum += A[l];
            }
            console.log(sum);
            */
        }
        else{
            r -= n;
            console.log(preSum[r+1] + preSum[n] - preSum[l]);
            /*
            let sum = 0;
            for(l; l < n; l++){
                sum += A[l];
                //console.log('sum:'+sum)
            }
            for(let i=0; i <= r; i++){
                sum += A[i];
                //console.log('sum:'+sum)
            }
            console.log(sum);
            */
        }
    }
}