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
    //動的計画法をやってみる
    const n = Number(input[0]);
    const parts = [];
    //全て胴体につけた場合の嬉しさと重さ
    let w0 = 0;
    let joy0 = 0;
    for(let i=0; i<n; i++){
        parts.push(input[i+1].split(' ').map(Number));
        w0 += parts[i][0];
        joy0 += parts[i][2];
    }
    //console.log(parts);

    const rowSize = Math.floor(w0/2)+1;
    const DP = [];
    DP.push(new Array(rowSize).fill(joy0))
    //console.log(DP);
    for(let i=1; i<n+1; i++){
        // 頭につけると嬉しさが上がる場合のみ考える
        if(parts[i-1][1] > parts[i-1][2]){
            //console.log(i, '番目の部品に対する操作を開始する')
            const DPColumn = [];
            for(let j=0; j<rowSize; j++){
                if(j>=parts[i-1][0]){
                    //console.log('頭につけるかつけないかで、嬉しさが大きい方が選ばれるはず', DP[i-1][j-parts[i-1][0]] + parts[i-1][1] - parts[i-1][2], DP[i-1][j])
                    DPColumn.push(Math.max(DP[i-1][j-parts[i-1][0]] + parts[i-1][1] - parts[i-1][2], DP[i-1][j]));
                }
                else{
                    //console.log('前と変わらない嬉しさになっているはず', DP[i-1][j])
                    DPColumn.push(DP[i-1][j]);
                }
            }
            DP.push(DPColumn);
            //console.log(i, '番目の部品に対する操作の結果', DPColumn)
        }
        else{
            //console.log('頭につけても嬉しさが増えないから操作しない')
            DP.push(DP[i-1]);
        }
    }
    console.log(DP[n][rowSize-1]);
});