# C 問題
10進法での回文を全列挙して調べる。

# D 問題
家の間の距離が大きい順に電波塔の管轄区域を分けていく。

n = m の場合、答えは 0 で即終了。

家の座標の vector を作成。ソートする
```cpp:house
vector<ll> house(n);
```
最初の家から最後の家までの距離 max_dist を求める。

隣り合う家の距離を求め、降順にソートする
```cpp:dist
vector<ll> dist(n-1);
sort(dist.rdegin(), dist.rend());
```

max_dist から、大きい順に m-1 個 dist を引くことができる。