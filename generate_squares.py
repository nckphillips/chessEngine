import string

filename = "square_instances.txt"
fileo = open(filename, "w+")

rank = ["a","b","c","d","e","f","g","h"]
file = [1,2,3,4,5,6,7,8]
squares = []
class Square:
    def __init__(self, s_id):
        self.name = str(rank[s_id%8]) + str(file[s_id/8])
        self.id = s_id
        self.in_connections = ["", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""]
        self.out_connections = ["", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""]
        self.connection_string = ""
    def gen_conn_string(self):
        self.connection_string = ".in_tl(" + self.in_connections[0] + "), .in_midl(" + self.in_connections[1] + "), .in_bl(" + self.in_connections[2] + "), .in_midb(" + self.in_connections[3] + "), .in_br(" + self.in_connections[4] + "), .in_midr(" + self.in_connections[5] + "), .in_tr(" + self.in_connections[6] + "), .in_midt(" + self.in_connections[7] + "), .in_klt(" + self.in_connections[8] + "), .in_klb(" + self.in_connections[9] + "), .in_krb(" + self.in_connections[10] + "), .in_krt(" + self.in_connections[11] + "), .in_ktl(" + self.in_connections[12] + "), .in_ktr(" + self.in_connections[13] + "), .in_kbl(" + self.in_connections[14] + "), .in_kbr(" + self.in_connections[15] + ")"
        self.connection_string += ".out_tl(" + self.out_connections[0] + "), .out_midl(" + self.out_connections[1] + "), .out_bl(" + self.out_connections[2] + "), .out_midb(" + self.out_connections[3] + "), .out_br(" + self.out_connections[4] + "), .out_midr(" + self.out_connections[5] + "), .out_tr(" + self.out_connections[6] + "), .out_midt(" + self.out_connections[7] + "), .out_klt(" + self.out_connections[8] + "), .out_klb(" + self.out_connections[9] + "), .out_krb(" + self.out_connections[10] + "), .out_krt(" + self.out_connections[11] + "), .out_ktl(" + self.out_connections[12] + "), .out_ktr(" + self.out_connections[13] + "), .out_kbl(" + self.out_connections[14] + "), .out_kbr(" + self.out_connections[15] + ")"

    def gen_connects(self):
        tlin = squares[self.id+7].name + self.name #top left, continue ccw
        tlout = self.name + squares[self.id + 7].name
        midlin = squares[self.id-1].name + self.name
        midlout = self.name + squares[self.id-1].name
        blin = squares[self.id-9].name + self.name
        blout = self.name + squares[self.id-9].name
        midbin = squares[self.id-8].name + self.name
        midbout = self.name + squares[self.id-8].name
        brin = squares[self.id-7].name + self.name
        brout = self.name + squares[self.id-7].name
        midrin = squares[self.id+1].name + self.name
        midrout = self.name + squares[self.id+1].name
        trin = squares[self.id+9].name + self.name
        trout = self.name + squares[self.id + 9].name
        midtin = squares[self.id + 8].name + self.name
        midtout =  self.name + squares[self.id + 8].name
        kltin = squares[self.id + 6].name + self.name
        kltout = self.name + squares[self.id+6].name
        klbin = squares[self.id-6].name + self.name
        klbout = self.name + squares[self.id-6].name
        krbin = squares[self.id-10].name + self.name
        krbout = self.name + squares[self.id-10].name
        krtin = squares[self.id + 10].name + self.name
        krtout = self.name + squares[self.id + 10].name
        ktlin =squares[self.id + 15].name + self.name
        ktlout = self.name + squares[self.id + 15].name
        ktrin = squares[self.id + 17].name + self.name
        ktrout = self.name + squares[self.id + 17].name
        kblin = squares[self.id-17].name + self.name
        kblout =  self.name + squares[self.id-17].name
        kbrin = squares[self.id-15].name + self.name
        kbrout = self.name + squares[self.id-15].name
        if (self.name == "a1") :
            print("ok")
        elif (self.name == "a8"):
            print("ok")
        elif (self.name == "h1"):
            print("ok")
        elif (self.name == "h8"):
            print("ok")
        elif (self.name[0] == "a"):
            print("ok")
        elif (self.name[0] == "h"):
            print("ok")
        elif (self.name[1] == "1"):
            print("ok")
        elif (self.name[1] == "8"):
            print("ok")
        else:
            self.in_connections[0] = tlin
            self.out_connections[0] = tlout
            self.in_connections[1] = midlin
            self.out_connections[1] = midlout
            self.in_connections[2] = blin
            self.out_connections[2] = blout
            self.in_connections[3] = midbin
            self.out_connections[3] = midbout
            self.in_connections[4] = brin
            self.out_connections[4] = brout
            self.in_connections[5] = midrin
            self.out_connections[5] = midrout
            self.in_connections[6] = trin
            self.out_connections[6] = trout
            self.in_connections[7] = midtin
            self.out_connections[7] = midtout
            self.in_connections[8] = kltin
            self.out_connections[8] = kltout
            self.in_connections[9] = klbin
            self.out_connections[9] = klbout
            self.in_connections[10] = krbin
            self.out_connections[10] = krbout
            self.in_connections[11] = krtin
            self.out_connections[11] = krtout
            self.in_connections[12] = ktlin
            self.out_connections[12] = ktlout
            self.in_connections[13] = ktrin
            self.out_connections[13] = ktrout
            self.in_connections[14] = kblin
            self.out_connections[14] = kblout
            self.in_connections[15] = kbrin
            self.out_connections[15] = kbrout


for i in range(0,63):
    squares.append(Square(i))


for s in squares:
    s.gen_connects()
    s.gen_conn_string()

#generate wires
wires = []#contains text wires to write to file
for s in squares:
    for i in range(0,16):
        if s.in_connections[i] not in wires:
            wires.append(s.in_connections[i])
        elif s.out_connections[i] not in wires:
            wires.append(s.out_connections[i])


for s in squares:
    fileo.write("square " + s.name + "(.clock(clk), .init(init), .occupied(" + str(s.id) + "_occ), .square_id(")
    fileo.write("5'd" + str(s.id) + ", .piece_type_calc(piece_type_calc), " + ".occupying_piece(" + str(s.id))
    fileo.write("_occupying_piece), " + s.connection_string + ", .movebit(move_wires[" + str(s.id) + "])")



fileo.close()
