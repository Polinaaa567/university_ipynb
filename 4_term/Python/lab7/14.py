def reverse():
    with open('input.dat', mode='r') as ifile:
        a = ifile.read()
    with open('output.dat', mode='w') as outfile:
        outfile.write(a[::-1])


reverse()
