# C++98 Standard Library Reference

## Headers

### 1. Containers
- `<vector>`: Dynamic array
  - `vector::push_back()`
  - `vector::pop_back()`
  - `vector::size()`
  - `vector::empty()`
  - `vector::clear()`
  - `vector::begin()`
  - `vector::end()`
  - `vector::front()`
  - `vector::back()`
  - `vector::reserve()`

- `<list>`: Doubly-linked list
  - `list::push_back()`
  - `list::push_front()`
  - `list::pop_back()`
  - `list::pop_front()`
  - `list::size()`
  - `list::empty()`
  - `list::clear()`
  - `list::splice()`
  - `list::remove()`
  - `list::unique()`
  - `list::merge()`
  - `list::sort()`
  - `list::reverse()`

- `<deque>`: Double-ended queue
  - `deque::push_back()`
  - `deque::push_front()`
  - `deque::pop_back()`
  - `deque::pop_front()`
  - `deque::size()`
  - `deque::empty()`
  - `deque::clear()`

- `<queue>`: FIFO queue adapter
  - `queue::push()`
  - `queue::pop()`
  - `queue::front()`
  - `queue::back()`
  - `queue::size()`
  - `queue::empty()`

- `<stack>`: LIFO stack adapter
  - `stack::push()`
  - `stack::pop()`
  - `stack::top()`
  - `stack::size()`
  - `stack::empty()`

- `<map>`: Sorted associative container
  - `map::insert()`
  - `map::erase()`
  - `map::find()`
  - `map::count()`
  - `map::lower_bound()`
  - `map::upper_bound()`
  - `map::equal_range()`
  - `map::size()`
  - `map::empty()`
  - `map::clear()`

- `<set>`: Sorted unique keys
  - `set::insert()`
  - `set::erase()`
  - `set::find()`
  - `set::count()`
  - `set::lower_bound()`
  - `set::upper_bound()`
  - `set::equal_range()`
  - `set::size()`
  - `set::empty()`
  - `set::clear()`

### 2. Algorithms `<algorithm>`
#### Sorting
- `sort()`
- `stable_sort()`
- `partial_sort()`
- `nth_element()`

#### Searching
- `find()`
- `find_if()`
- `binary_search()`
- `lower_bound()`
- `upper_bound()`
- `equal_range()`

#### Modifying Sequence Operations
- `copy()`
- `copy_backward()`
- `fill()`
- `fill_n()`
- `transform()`
- `generate()`
- `generate_n()`
- `replace()`
- `replace_if()`
- `swap()`
- `iter_swap()`

#### Removing Elements
- `remove()`
- `remove_if()`
- `unique()`

#### Mutating Operations
- `reverse()`
- `rotate()`
- `random_shuffle()`

#### Partitioning
- `partition()`
- `stable_partition()`

#### Sorting Operations
- `make_heap()`
- `push_heap()`
- `pop_heap()`
- `sort_heap()`

#### Set Operations
- `set_union()`
- `set_intersection()`
- `set_difference()`
- `set_symmetric_difference()`

### 3. Input/Output `<iostream>`
#### Stream Classes
- `istream`
- `ostream`
- `iostream`
- `ifstream`
- `ofstream`
- `fstream`
- `stringstream`

#### Stream Objects
- `cin`
- `cout`
- `cerr`
- `clog`

#### Stream Manipulators
- `endl`
- `flush`
- `ws`
- `ends`
- `setw()`
- `setfill()`
- `setprecision()`
- `fixed`
- `scientific`

### 4. String Operations `<string>`
- `string::append()`
- `string::assign()`
- `string::insert()`
- `string::erase()`
- `string::replace()`
- `string::substr()`
- `string::find()`
- `string::rfind()`
- `string::find_first_of()`
- `string::find_last_of()`
- `string::find_first_not_of()`
- `string::find_last_not_of()`
- `string::compare()`
- `string::c_str()`
- `string::data()`
- `string::length()`
- `string::size()`
- `string::empty()`
- `string::clear()`

### 5. Numeric Operations `<numeric>`
- `accumulate()`
- `inner_product()`
- `partial_sum()`
- `adjacent_difference()`

### 6. Memory Management
#### `<memory>`
- `auto_ptr`
- `allocator`
- `uninitialized_copy()`
- `uninitialized_fill()`
- `uninitialized_fill_n()`

### 7. Exception Handling `<exception>`
- `exception`
- `bad_alloc`
- `bad_cast`
- `bad_typeid`
- `bad_exception`
- `unexpected()`
- `set_unexpected()`
- `terminate()`
- `set_terminate()`
- `uncaught_exception()`

### 8. Utilities
#### `<utility>`
- `pair`
- `make_pair()`
- `operator==`
- `operator<`

#### `<functional>`
##### Function Objects
- `plus`
- `minus`
- `multiplies`
- `divides`
- `modulus`
- `negate`
- `equal_to`
- `not_equal_to`
- `greater`
- `less`
- `greater_equal`
- `less_equal`
- `logical_and`
- `logical_or`
- `logical_not`

##### Function Adapters
- `bind1st()`
- `bind2nd()`
- `ptr_fun()`
- `mem_fun()`
- `mem_fun_ref()`

### 9. C Library Wrappers
- `<cstdlib>`
- `<cstdio>`
- `<cstring>`
- `<cctype>`
- `<cmath>`
- `<ctime>`
- `<cerrno>`
- `<clocale>`
- `<climits>`
- `<cfloat>`
- `<cassert>`
- `<csignal>`
- `<csetjmp>`
- `<cstdarg>`

Note: This list includes the most commonly used functions and features of the C++98 standard library. Some implementation-specific extensions or less commonly used features might not be included.
