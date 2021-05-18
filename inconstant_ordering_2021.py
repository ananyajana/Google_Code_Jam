from collections import OrderedDict

T = int(input())
n_list =[]
num_list =[]
for t in range(T):
    x = int(input())
    n_list.append(x)
    y = input().split()
    y = [int(y[i]) for i in range(len(y))]
    num_list.append(y)

''' find the alphabetically first valid string '''
# alphabetically first valid string means which letters
# should be part of the string e.g. if L1 is 1, then
# the string can only be AB and not AZ
# a block depends only on its preceding letter so that
# preceding letter needs to be kept track of
# if the size of the odd block's is greater than the size of 
# the next eve block, then there is not much to think of
# but if the odd block's size is less than the size of the
# next even block then the last character of the odd block
# needs to be adjusted
# interestingly this is not symetric means the odd block
# even block scenario is interesting, but not even block
# odd block?
# the even block is fairly simple, if there are 4 chars
# in the even block then first four charas in reverse order?
def create_ordering(n, arr):
    # the variable to hold the preceding character
    pre_char = 'A'
    valid_str = "A"
    
    # start filling the blocks. A block is dependent only 
    # on the preceding character. It does not impact the
    # far away blocks in any way?
    # the -1 is because every time we will check for the
    # size of the next bloc
    for i in range(len(arr) - 1):
        # the block is even 
        if (i + 1)% 2 == 1:
            diff = None
            if arr[i+1] > arr[i]:
                # take the diff in size and that's what needs to e added to the
                # last charc of the odd bloc
                diff = arr[i+1] - arr[i]
                #else:
            inc = 1 # the increment amount to create the last char in the current block
            for j in range(arr[i]):
                if diff is not None and j == arr[i]-1:
                    inc += diff
                temp = chr(ord(pre_char) + inc)
                pre_char = temp
                valid_str += temp

        else:
            temp = chr(ord('A') + arr[i] - 1)
            for k in range(arr[i]):
                #print('Valid_str: ', valid_str)
                valid_str += temp
                temp = chr(ord(temp) - 1)
                
    # handle the last block based on whether it is even or odd
    arr_len = len(arr)
    last_block_len = arr[-1]
    if arr_len % 2 == 1:
        inc = 1
        for j in range(last_block_len):
            temp = chr(ord(pre_char) + inc)
            pre_char = temp
            valid_str += temp
    else:
        temp = chr(ord('A') + last_block_len - 1)
        for k in range(last_block_len):
            #print('Valid_str: ', valid_str)
            valid_str += temp
            temp = chr(ord(temp) - 1)


    return valid_str

''' in create_ordering function, we note that we create the forward and back
strings every time by iteration which may not be necessary we can create two
different memoization tables which will take constant time to access since the
size of the table is determined by the size of the alphabet and hence fixed'''
# one important thing to notice is that neither the odd block nor the even
# block can have a size of 26, but odd block size 25 and even block size 24
# is possible
def create_ordering2(n, arr):
    # now let's start creating the required string dependeing on the
    # length and number of blocks
    valid_str = "A"
    arr_len = len(arr)
    for i in range(arr_len):
        # length of the current block
        block_len = arr[i]
        # check if odd block
        if (i + 1)% 2 == 1:
            diff = None
            if i != (arr_len - 1) and arr[i+1] > arr[i]:
                # take the diff in size and that's what needs to e added to the
                # last charc of the odd bloc
                diff = arr[i+1] - arr[i]
            # the last char of the block would be either 'A' + (block_len - 1) or 'A' + block_len - 1 + diff
            if diff is None:
                valid_str += forward_tb[block_len] + chr(ord('A') + block_len) 
            else:
                valid_str += forward_tb[block_len] + chr(ord('A') + block_len + diff) 
        else:
            #print('block_len: ', block_len)
            valid_str += backward_tb[block_len] 
    
    return valid_str

# another observation is that the two memoization tables need to be created only once
# and hence the forward_tb and backward_tb can be global vars
forward_tb = dict()
backward_tb = dict()

def create_memoization_table():
    # the odd block can only start with B
    alph_len = ord('Z') - ord('A') + 1  # length of the alphabet
    # create a hash table for holding forward memoization
    #forward_tb = dict()
    #cur_str = "A"
    cur_str = ""
    for i in range(alph_len):
        #cur_str += chr(ord("A") + i)
        # we do one more trick, as we know last char of the odd block
        # is dependent on the succeeding even block's length. Hence we
        # keep don't fill in the last char in the memoization table
        # beecase strings are immutable and hence we cannot change the
        # last char of the string at the time of actually filling the block
        # rather the last char is determinied at runtime and then filled
        # e.g. if odd block length is 3, the hash table entry for 3 is AB
        # and the last char whether C or something else will be filled at
        # runtime
        # such consideration is not needed for backward table though
        # anothe rimportant observation is that odd block will always
        # start with 'B' and hence the forward memization table needs to
        # b adjusted and also the block length limitations changed accordingly
        forward_tb[i+1] = cur_str
        cur_str += chr(ord("B") + i)
    
    #print('forward memoization table:')
    #print(forward_tb)

    # create a hash table holding backward memoization
    #backward_tb = dict()
    #cur_str = "A"
    cur_str = ""
    for i in range(alph_len):
        cur_str = chr(ord("A") + i) + cur_str
        backward_tb[i+1] = cur_str
    #print('backward memoization table:')
    #print(backward_tb)

create_memoization_table()

for t in range(T):
    #s1 = input()
    '''
    s1 = st_list[t]
    t1 = tgt_list[t]
    is_anagram(s1, t1)
    '''
    #print('n_list: ', n_list)
    #print('num_list: ', num_list)
    #print('case #{}: {}'.format((t+1), create_ordering(n_list[t], num_list[t])))
    print('case #{}: {}'.format((t+1), create_ordering2(n_list[t], num_list[t])))
