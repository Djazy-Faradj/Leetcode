class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        Stack<Integer> tracker = new Stack<>();
        for (int i = 0; i < flowerbed.length; i++) {
            if (flowerbed[i] == 1) {
                if (tracker.size() != 0 && tracker.peek() == 1) {
                    n++;
                } else {
                    tracker.push(1);
                }
            } else if (flowerbed[i] == 0) {
                if (tracker.size() == 0) {
                    n--;
                    tracker.push(1);
                }
                else {
                    tracker.pop();
                }
            }
        }
        return n <= 0;
    }
}