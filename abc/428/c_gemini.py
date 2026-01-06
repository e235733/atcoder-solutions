import sys

# 高速な入力を受け取るためのおまじない
# AtCoderではよく使われます
input = sys.stdin.readline

def main():
    q = int(input())

    # balance_stack: 現在の括弧のバランスを記録するスタック
    # min_balance_stack: 各時点での接頭辞の最小バランスを記録するスタック
    # 初期状態（空文字列）はバランス0なので、[0]を入れておく
    balance_stack = [0]
    min_balance_stack = [0]

    for _ in range(q):
        query = input().split()

        # クエリ1: 文字の追加
        if query[0] == '1':
            char = query[1]
            
            # 直前のバランスを取得
            last_balance = balance_stack[-1]
            
            # 新しいバランスを計算
            if char == '(':
                new_balance = last_balance + 1
            else: # ')'
                new_balance = last_balance - 1
            
            # バランスの履歴をスタックに追加
            balance_stack.append(new_balance)
            
            # 直前の最小バランスと新しいバランスを比較し、小さい方を記録
            last_min_balance = min_balance_stack[-1]
            min_balance_stack.append(min(last_min_balance, new_balance))

        # クエリ2: 文字の削除
        else:
            # スタックの末尾から履歴を削除する (O(1)の操作)
            balance_stack.pop()
            min_balance_stack.pop()

        # 判定
        # 1. 最終バランスが0であること
        # 2. 途中の最小バランスが0以上であること (0から始まるので0はOK)
        # この2つを両方満たせば「良い括弧列」
        if balance_stack[-1] == 0 and min_balance_stack[-1] == 0:
            print('Yes')
        else:
            print('No')

if __name__ == '__main__':
    main()