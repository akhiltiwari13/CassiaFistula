// ============================================================================
//                    SPECIFICATION PATTERN
// ============================================================================
#include<vector>
/*
 * SPECIFICATION pattern follows the open close principle.
 */
template <typename T> struct ISpecification {
  // This Interface defines the criteria which needs to be statisfied.
  virtual bool is_satisfied(T *item) = 0;
};

/**
 * This generic base class is open for extension but closed for modification.
 */
template <typename T> struct IFilter {
  // This Interface defines filtration criteria.
  /**
   *
   * @param items List of data to Filter.
   * @param specification The spec instance.
   * @return
   */
  virtual std::vector<T *> filter(std::vector<T *> items,
                                  ISpecification<T> &spec) = 0;
};

template <typename T> struct AndSpecification : ISpecification<T> {
  // This Interface defines filtration criteria based on 2 specification
  ISpecification<T> &spec_a;
  ISpecification<T> &spec_b;

  AndSpecification(ISpecification<T> &spec_a, ISpecification<T> &spec_b)
      : spec_a(spec_a), spec_b(spec_b) {}

  bool is_satisfied(T *item) override {
    return spec_a.is_satisfied(item) && spec_b.is_satisfied(item);
  }
};
