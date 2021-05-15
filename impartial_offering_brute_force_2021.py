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

def calculate_offering(n, arr):
    arr.sort()

    # create a hshmap where keys are the entries from arr and values
    # are the counts
    od = OrderedDict()
    for i in range(len(arr)):
        if arr[i] not in od:
            od[arr[i]] = 1
        else:
            od[arr[i]] += 1
    
    print(od)

    treat_size = 1
    count = 0
    for key in od.keys():
        count += od[key] * treat_size # multiply the current treat_size with 
        # the current numbe of pets with the particular size i.e. key
    
        treat_size += 1 # increment the treat_size because pet size
        # is increased in the next key else the next key would not be different
        # from the current key

    print('count: ', count)
            

for t in range(T):
    #s1 = input()
    '''
    s1 = st_list[t]
    t1 = tgt_list[t]
    is_anagram(s1, t1)
    '''
    print('n_list: ', n_list)
    print('num_list: ', num_list)
    calculate_offering(n_list[t], num_list[t])
