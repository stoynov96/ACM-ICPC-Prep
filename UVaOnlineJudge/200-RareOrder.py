
class Position:
    def __init__(self, start, end):
        self.start = start
        self.end = end


# DEBUG
def dumpdict(letters_dict):
    print("Dumping dict with count = {0}".format(len(letters_dict)))
    for data in letters_dict:
        print('{0}: ({1}.{2})'.format(data, letters_dict[data].start, letters_dict[data].end))

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

    # debug
    # dumpdict(letters_dict)


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


def get_order_string(orders_array):

    # Dictionary to store the letters start and end positions 
    letters_dict = get_letters_dict(orders_array)

    # Repeat the main procedure as many times as the number of unique letters is
    for i in range(len(letters_dict)):
        shrink_ranges(orders_array, letters_dict)

    ret_string = [''] * len(letters_dict)
    for key in letters_dict:
        ret_string[letters_dict[key].start] = key

    return ''.join(ret_string)
    


def get_orders_array(string_list, max_len):

    orders_array = []
    ind = 0
    group_seperators = []
    gs_next_ind = 0

    while ind < max_len:

        c_char = '*'
        this_order = []
        gs_next_ind = 0

        # print("ind =", ind) # debug
        
        for i in range(len(string_list)):
            s = string_list[i]

            marked_gs = False

            # Clear if new group
            # print("  i = {0}, s = {1}".format(i,s)) # debug
            # print("  gseperators:", group_seperators) # debug
            # print("  gs_next_ind:", gs_next_ind) # debug
            # print()
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
# orders_array = ['XZYK', 'WK', 'XAK', 'XWZ', 'XAW']
# orders_array = ['XZY', 'YW']
orders_array = get_orders_array(string_list, max_len)

# print('orders_array:', orders_array)

# === Solve Problem ===
print(get_order_string(orders_array))
    
