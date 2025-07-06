    class Solution {
    public int singleNumber(int[] nums) {
        HashSet<Integer> tracker = new HashSet<>();
        for (int i = 0; i < nums.length; i++) {
            if (!tracker.add(nums[i])) {
                tracker.remove(nums[i]);
            }
        }
        return (int) (tracker.toArray()[0]);
    }
}