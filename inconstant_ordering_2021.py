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

for t in range(T):
    #s1 = input()
    '''
    s1 = st_list[t]
    t1 = tgt_list[t]
    is_anagram(s1, t1)
    '''
    #print('n_list: ', n_list)
    #print('num_list: ', num_list)
    print('case #{}: {}'.format((t+1), create_ordering(n_list[t], num_list[t])))
