
class Position:
    def __init__(self, start, end):
        self.start = start
        self.end = end



"""
Main portion of the problem's solution. This shrinks the ranges of each letter
until a specific ordered index is found (start of range equals end of range)

Params:
    orders_array:       array of 'orders'* - term explained below
    letters_dict:       unordered set linking letters to their ranges

Terminology:
    *'order' - an order is a string in which all letters are oredered according to the 
                language's rules    
"""
def shrink_ranges(orders_array, letters_dict):

    for order_string in orders_array:
        for i in range(len(order_string) - 1):
            # this is before the next one
            letters_dict[order_string[i]].end = min ( 
                letters_dict[order_string[i]].end,      # first min parameter
                letters_dict[order_string[i+1]].end - 1 # second min pararmeter
                )
            # next one is after this one
            letters_dict[order_string[i+1]].start = max (
                letters_dict[order_string[i+1]].start,  # first max parameter
                letters_dict[order_string[i]].start + 1 # second max parameter
                )


"""
Creates a letters dictionary from an orders array.
The initial range for each letter is 0 to (number_of_letters-1)
"""
def get_letters_dict(orders_array):

    letters_dict = {}

    # Initial fill of dictionary
    #   - initialize & count total unique letters
    letters_count = 0
    for ord_str in orders_array:
        for c in ord_str:
            if not c in letters_dict:
                letters_count += 1
                letters_dict[c] = Position(0,0)

    #   - fill dictionary
    letters_count -= 1
    for data in letters_dict:
        letters_dict[data].end = letters_count

    return letters_dict


"""
Transforms an array of orders to an alphabet - a string consisting of all
unique letters in correct order (left to right)
"""
def get_order_string(orders_array):

    # Dictionary to store the letters start and end positions 
    letters_dict = get_letters_dict(orders_array)

    # Repeat the main procedure as many times as the number of unique letters is
    for i in range(len(letters_dict)):
        shrink_ranges(orders_array, letters_dict)

    # Create an alphabet string from the letters dictionary
    ret_string = [''] * len(letters_dict)
    for key in letters_dict:
        ret_string[letters_dict[key].start] = key

    return ''.join(ret_string)


"""
Converts a list of strings to an array of orders. Each element of that array is a string
that is ordered according to the language's rules.
Strings of length 1 are ignored because they do not hold any valuable information

Example:
An input of:        will be converted to ['XZY', 'YW']
XWY
ZX
ZXY
ZXW
YWWX

Params:
    string_list:        List of original strings to be converted to orders arrays
"""
def get_orders_array(string_list, max_len):

    # To return
    orders_array = []
    # Index in original string (a.k.a column)
    ind = 0

    # Endings indeces of 'groups'
    # a 'group' is a collection of letters that are ordered in the input
    group_seperators = []
    # Place in the group_seperators array of the next group ending index
    gs_next_ind = 0

    while ind < max_len:

        c_char = '*'
        this_order = []
        gs_next_ind = 0
        
        for i in range(len(string_list)):
            s = string_list[i]

            # if group seperator is marked, it should not be marked again later
            marked_gs = False

            # Mark a group seperator and clean variables to start a new order
            if gs_next_ind < len(group_seperators) and group_seperators[gs_next_ind] == i:
                if len(this_order) > 1: orders_array.append(this_order)
                c_char = "*"
                this_order = []

                marked_gs = True

                gs_next_ind += 1


            # Is it too short for this index?
            if len(s) <= ind:
                continue

            # New character encountered
            if c_char != s[ind]:

                # Group Seperators
                if not marked_gs and (gs_next_ind >= len(group_seperators) or i != group_seperators[gs_next_ind]):
                    group_seperators = group_seperators[:gs_next_ind] + [i] + group_seperators[gs_next_ind:]
                    gs_next_ind += 1

                this_order.append(s[ind])

                c_char = s[ind]

        # Append if meaningful information
        if len(this_order) > 1:
            orders_array.append(this_order)

        ind += 1

    return orders_array









# === Get input === 
max_len = 0
string_list = []

s = ''
while s != '#':
    s = input()
    string_list.append(s)
    max_len = max(max_len, len(s))
del string_list[-1]

# === Transform input into usable form ===
orders_array = get_orders_array(string_list, max_len)

# === Solve Problem ===
print(get_order_string(orders_array))
    
