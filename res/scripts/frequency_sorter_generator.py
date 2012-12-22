#a meta-python program to generate sorted frequencies of alphabets and symbols from english alphabets based on a input file called "frequencies"

def construct_sorted_frequencies_hash_map(file_input):
    file_input = file_input.split(''',''')
    return_value = '''{'''
    for values in file_input:
        return_value += ("""'""" + values.split(''':''')[0] + """'""" + ''' : ''' + values.split(''':''')[1])
        return_value += (''', ''')
    return_value = return_value[:-2]
    return_value += ('''}''')
    return return_value

file_input = open('''frequencies''','''r''')
sorted_frequencies_tree = construct_sorted_frequencies_hash_map(file_input.read())
file_output = open('''frequency_sorter.py''','''w''')
file_output.write('''#a dictionary realting alphabets to their frequencies from a standard corpus\n''')
file_output.write('''dict = '''+sorted_frequencies_tree+'''\n''')
file_output.write('''sorted_frequencies = sorted(dict.iteritems(), key=lambda (k,v): (v,k))\n''')