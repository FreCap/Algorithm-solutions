
struct RangeData {
  int gcd = 0;

  RangeData(int gcd) : gcd(gcd) {
  }

  RangeData() {
  }

  int do_gcd(int a, int b) {
    return b ? do_gcd(b, a % b) : a;
  }

  RangeData operator ^ (const RangeData& other) {
    return RangeData(do_gcd(gcd, other.gcd));
  }
};

struct Range {
  int l, r;
  RangeData data;
  Range *left = NULL, *right = NULL;

  Range(int l, int r) : l(l), r(r) {
  }

  Range() : Range(std::numeric_limits<int>::max(), std::numeric_limits<int>::min()) {
  }

  int size() {
    return r - l;
  }
};

class Rangetree {
private:
  Range* root;
  int* array;

  Range* build(int l, int r) {
    assert(l <= r);
    if (r - l == 1) {
      Range* range = new Range(l, r);
      range->data = RangeData(array[l]);
      return range;
    }
    Range* range = new Range(l, r);
    int m = l + (r - l) / 2;
    range->left  = build(l, m);
    range->right = build(m, r);
    range->data  = range->left->data ^ range->right->data;
    return range;
  }

  RangeData query(Range* range, int l, int r) {
    if (r <= range->l || l >= range->r) {
      return Range().data;
    }
    if (l <= range->l && r >= range->r) {
      return range->data;
    }
    return query(range->left, l, r) ^ query(range->right, l, r);
  }

public:
  Rangetree(int *array, int size) {
    this->array = array;
    root = build(0, size);
  }

  RangeData query(int l, int r) {
    r++;
    return query(root, l, r);
  }
};
