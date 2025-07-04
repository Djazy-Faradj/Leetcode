class Solution {
    public int largestAltitude(int[] gain) {
        if (gain.length == 0) return 0;

        ArrayList<Integer> positions = new ArrayList<>();
        int pos = 0;
        positions.add(pos);

        for (int i = 0; i < gain.length; i++) {
            pos += gain[i];
            positions.add(pos);
        }
        positions.sort(null);
        return positions.get(positions.size()-1);
    }
}