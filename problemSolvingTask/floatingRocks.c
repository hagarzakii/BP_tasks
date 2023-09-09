int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int solve(int x1, int y1, int x2, int y2) {
    int diffx = abs(x1 - x2);
    int diffy = abs(y1 - y2);
    int greatestcd = gcd (diffx , diffy );
    return greatestcd-1;
}