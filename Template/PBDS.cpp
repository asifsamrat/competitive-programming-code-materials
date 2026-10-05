#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, std::less_equal<T>, rb_tree_tag,
  tree_order_statistics_node_update>;

/* usage :
 * order_of_key(k) : Gives the count of element smaller than k.
 * find_by_order(k) : Returns the iterator for the k-th element (0-based)
 * deletion in multiset :
 *      s.erase(s.find_by_order(s.order_of_key(k)));
 */
