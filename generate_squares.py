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
            self.in_connections[0] = squares[self.id+7].name + self.name #top left, continue ccw
            self.out_connections[0] = self.name + squares[self.id + 7]
            self.in_connections[1] = squares[self.id-1].name + self.name
            self.out_connections[1] = self.name + squares[self.id-1]
            self.in_connections[2] = squares[self.id-9].name + self.name
            self.out_connections[2] = self.name + squares[self.id-9].name
            self.in_connections[3] = squares[self.id-8].name + self.name
            self.out_connections[3] = self.name + squares[self.id-8]
            self.in_connections[4] = squares[self.id-7] + self.name
            self.out_connections[4] = self.name + squares[self.id-7]
            self.in_connections[5] = squares[self.id+1] + self.name
            self.out_connections[5] = self.name + squares[self.id+1]
            self.in_connections[6] = squares[self.id+9] + self.name
            self.out_connections[6] = self.name + squares[self.id + 8]
            self.in_connections[7] =
            self.out_connections[7] =
            self.in_connections[8] =
            self.out_connections[8] =
            self.in_connections[9] =
            self.out_connections[9] =
            self.in_connections[10] =
            self.out_connections[10] =
            self.in_connections[11] =
            self.out_connections[11] =
            self.in_connections[12] =
            self.out_connections[12] =
            self.in_connections[13] =
            self.out_connections[13] =
            self.in_connections[14] =
            self.out_connections[14] =
            self.in_connections[15] =
            self.out_connections[15] =


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
