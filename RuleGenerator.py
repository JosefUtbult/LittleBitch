def getComma(instance):
    if(instance < 9):
        return ","

    else:
        return ""

titles = ['Home', 'Looper', 'Move', 'Page 1', 'Page 2', 'Page 3', 'Page 4', 'Page 5', 'Page 6', 'Page 7']

for page in range(0, 10):

    temp = ""

    temp += '\t{\n'
    temp += '\t\t//\t==============\n'
    temp += '\t\t//\t   PAGE %d   \n' % page
    temp += '\t\t//\t==============\n'
    temp += '\n'
    temp += '\t\t\"%s\",\t//Display Letters\n' % titles[page]
    temp += '\t\t{\t//ControllBanks'

    print(temp)
    temp = ""

    for bank in range(0, 4):

        temp += '\t\t\t{\n\t\t\t\t//\t==============\n'
        temp += '\t\t\t\t//\t   BANK %d   \n' % (bank + page * 4)
        temp += '\t\t\t\t//\t==============\n'
        temp += '\n'
        temp += '\t\t\t\t%d,\t//Primary midi control\n' % ((bank + page * 4) * 2)
        temp += '\t\t\t\t-1,\t//Secondary midi control\n'
        temp += '\t\t\t\ttrue,\t//Flip\n'
        temp += '\t\t\t\tfalse,\t//DoubleClick\n'
        temp += '\n'
        temp += '\t\t\t\t%d,\t//Expression midi controll\n' % ((bank + page * 4) * 2 + 1)
        temp += '\t\t\t}%s' % getComma(bank)

        print(temp)
        temp = ""

    temp += '\t\t}\n'
    temp += '\t},'
    temp += '\n'

    print(temp)
    temp = ""