class Solution {
    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
        List<List<Integer>> answer = new ArrayList<>();
        HashSet<Integer> s1 = new HashSet<>();
        HashSet<Integer> s2 = new HashSet<>();
        ArrayList<Integer> distinct1 = new ArrayList<>();
        ArrayList<Integer> distinct2 = new ArrayList<>();

        for (Integer i : nums1) {
            s1.add(i);
        }
        for (Integer i : nums2) {
            s2.add(i);
        }

        for (Integer i : s1) {
            if (!s2.contains(i)) distinct1.add(i);
        }
        for (Integer i : s2) {
            if (!s1.contains(i)) distinct2.add(i);
        }

        answer.add(distinct1);
        answer.add(distinct2);

        return answer;
    }
}