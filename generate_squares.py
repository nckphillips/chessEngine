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

        self.tlin = "0" #top left, continue ccw
        self.tlout = "0"
        self.midlin = "0"
        self.midlout = "0"
        self.blin = "0"
        self.blout = "0"
        self.midbin = "0"
        self.midbout = "0"
        self.brin = "0"
        self.brout = "0"
        self.midrin = "0"
        self.midrout = "0"
        self.trin = "0"
        self.trout = "0"
        self.midtin = "0"
        self.midtout =  "0"
        self.kltin = "0"
        self.kltout = "0"
        self.klbin = "0"
        self.klbout = "0"
        self.krbin = "0"
        self.krbout = "0"
        self.krtin = "0"
        self.krtout = "0"
        self.tlin ="0"
        self.tlout = "0"
        self.trin = "0"
        self.trout = "0"
        self.blin = "0"
        self.blout =  "0"
        self.brin = "0"
        self.brout = "0"



    def gen_conn_string(self):
        self.connection_string = ".in_tl(" + self.in_connections[0] + "), .in_midl(" + self.in_connections[1] + "), .in_bl(" + self.in_connections[2] + "), .in_midb(" + self.in_connections[3] + "), .in_br(" + self.in_connections[4] + "), .in_midr(" + self.in_connections[5] + "), .in_tr(" + self.in_connections[6] + "), .in_midt(" + self.in_connections[7] + "), .in_klt(" + self.in_connections[8] + "), .in_klb(" + self.in_connections[9] + "), .in_krb(" + self.in_connections[10] + "), .in_krt(" + self.in_connections[11] + "), .in_ktl(" + self.in_connections[12] + "), .in_ktr(" + self.in_connections[13] + "), .in_kbl(" + self.in_connections[14] + "), .in_kbr(" + self.in_connections[15] + ")"
        self.connection_string += ".out_tl(" + self.out_connections[0] + "), .out_midl(" + self.out_connections[1] + "), .out_bl(" + self.out_connections[2] + "), .out_midb(" + self.out_connections[3] + "), .out_br(" + self.out_connections[4] + "), .out_midr(" + self.out_connections[5] + "), .out_tr(" + self.out_connections[6] + "), .out_midt(" + self.out_connections[7] + "), .out_klt(" + self.out_connections[8] + "), .out_klb(" + self.out_connections[9] + "), .out_krb(" + self.out_connections[10] + "), .out_krt(" + self.out_connections[11] + "), .out_ktl(" + self.out_connections[12] + "), .out_ktr(" + self.out_connections[13] + "), .out_kbl(" + self.out_connections[14] + "), .out_kbr(" + self.out_connections[15] + ")"

    def do_special_knights(self):
	if(self.name == "b2"):
            self.kltin = "0"
            self.kltout = "0"
            self.klbin = "0"
            self.klbout = "0"
            self.krbin = squares[self.id-10].name + self.name
            self.krbout = self.name + squares[self.id-10].name
            self.krtin = squares[self.id + 10].name + self.name
            self.krtout = self.name + squares[self.id + 10].name
            self.ktlin =squares[self.id + 15].name + self.name
            self.ktlout = self.name + squares[self.id + 15].name
            self.ktrin = squares[self.id + 17].name + self.name
            self.ktrout = self.name + squares[self.id + 17].name
            self.kblin = "0"
            self.kblout =  "0"
            self.kbrin = "0"
            self.kbrout = "0"
        elif(self.name == "b7"):
            self.kltin = "0"
            self.kltout = "0"
            self.klbin = "0"
            self.klbout = "0"
            self.krbin = squares[self.id-10].name + self.name
            self.krbout = self.name + squares[self.id-10].name
            self.krtin = squares[self.id + 10].name + self.name
            self.krtout = self.name + squares[self.id + 10].name
            self.ktlin = "0"
            self.ktlout = "0"
            self.ktrin = "0"
            self.ktrout = "0"
            self.kblin = squares[self.id-17].name + self.name
            self.kblout =  self.name + squares[self.id-17].name
            self.kbrin = squares[self.id-15].name + self.name
            self.kbrout = self.name + squares[self.id-15].name
        elif(self.name == "g2"):
	    self.kltin = squares[self.id + 6].name + self.name
            self.kltout = self.name + squares[self.id+6].name
            self.klbin = squares[self.id-6].name + self.name
            self.klbout = self.name + squares[self.id-6].name
            self.krbin = "0"
            self.krbout = "0"
            self.krtin = "0"
            self.krtout = "0"
            self.ktlin =squares[self.id + 15].name + self.name
            self.ktlout = self.name + squares[self.id + 15].name
            self.ktrin = squares[self.id + 17].name + self.name
            self.ktrout = self.name + squares[self.id + 17].name
            self.kblin = "0"
            self.kblout =  "0"
            self.kbrin = "0"
            self.kbrout = "0"
        elif(self.name == "g7"):
	    self.kltin = squares[self.id + 6].name + self.name
            self.kltout = self.name + squares[self.id+6].name
            self.klbin = squares[self.id-6].name + self.name
            self.klbout = self.name + squares[self.id-6].name
            self.krbin = "0"
            self.krbout = "0"
            self.krtin = "0"
            self.krtout = "0"
            self.ktlin = "0"
            self.ktlout = "0"
            self.ktrin = "0"
            self.ktrout = "0"
            self.kblin = squares[self.id-17].name + self.name
            self.kblout =  self.name + squares[self.id-17].name
            self.kbrin = squares[self.id-15].name + self.name
            self.kbrout = self.name + squares[self.id-15].name
        elif(self.name[0] == "b"):
	    self.kltin = "0"
            self.kltout = "0"
            self.klbin = "0"
            self.klbout = "0"
            self.krbin = squares[self.id-10].name + self.name
            self.krbout = self.name + squares[self.id-10].name
            self.krtin = squares[self.id + 10].name + self.name
            self.krtout = self.name + squares[self.id + 10].name
            self.ktlin =squares[self.id + 15].name + self.name
            self.ktlout = self.name + squares[self.id + 15].name
            self.ktrin = squares[self.id + 17].name + self.name
            self.ktrout = self.name + squares[self.id + 17].name
            self.kblin = squares[self.id-17].name + self.name
            self.kblout =  self.name + squares[self.id-17].name
            self.kbrin = squares[self.id-15].name + self.name
            self.kbrout = self.name + squares[self.id-15].name
        elif(self.name[0] == "g"):
	    self.kltin = squares[self.id + 6].name + self.name
            self.kltout = self.name + squares[self.id+6].name
            self.klbin = squares[self.id-6].name + self.name
            self.klbout = self.name + squares[self.id-6].name
            self.krbin = "0"
            self.krbout = "0"
            self.krtin = "0"
            self.krtout = "0"
            self.ktlin =squares[self.id + 15].name + self.name
            self.ktlout = self.name + squares[self.id + 15].name
            self.ktrin = squares[self.id + 17].name + self.name
            self.ktrout = self.name + squares[self.id + 17].name
            self.kblin = squares[self.id-17].name + self.name
            self.kblout =  self.name + squares[self.id-17].name
            self.kbrin = squares[self.id-15].name + self.name
            self.kbrout = self.name + squares[self.id-15].name
        elif(self.name[1] == "2"):
	    self.kltin = squares[self.id + 6].name + self.name
            self.kltout = self.name + squares[self.id+6].name
            self.klbin = squares[self.id-6].name + self.name
            self.klbout = self.name + squares[self.id-6].name
            self.krbin = squares[self.id-10].name + self.name
            self.krbout = self.name + squares[self.id-10].name
            self.krtin = squares[self.id + 10].name + self.name
            self.krtout = self.name + squares[self.id + 10].name
            self.ktlin =squares[self.id + 15].name + self.name
            self.ktlout = self.name + squares[self.id + 15].name
            self.ktrin = squares[self.id + 17].name + self.name
            self.ktrout = self.name + squares[self.id + 17].name
            self.kblin = "0"
            self.kblout =  "0"
            self.kbrin = "0"
            self.kbrout = "0"
        elif(self.name[1] == "7"):
	    self.kltin = squares[self.id + 6].name + self.name
            self.kltout = self.name + squares[self.id+6].name
            self.klbin = squares[self.id-6].name + self.name
            self.klbout = self.name + squares[self.id-6].name
            self.krbin = squares[self.id-10].name + self.name
            self.krbout = self.name + squares[self.id-10].name
            self.krtin = squares[self.id + 10].name + self.name
            self.krtout = self.name + squares[self.id + 10].name
            self.ktlin = "0"
            self.ktlout = "0"
            self.ktrin = "0"
            self.ktrout = "0"
            self.kblin = squares[self.id-17].name + self.name
            self.kblout =  self.name + squares[self.id-17].name
            self.kbrin = squares[self.id-15].name + self.name
            self.kbrout = self.name + squares[self.id-15].name

	else:
	    self.kltin = squares[self.id + 6].name + self.name
            self.kltout = self.name + squares[self.id+6].name
            self.klbin = squares[self.id-6].name + self.name
            self.klbout = self.name + squares[self.id-6].name
            self.krbin = squares[self.id-10].name + self.name
            self.krbout = self.name + squares[self.id-10].name
            self.krtin = squares[self.id + 10].name + self.name
            self.krtout = self.name + squares[self.id + 10].name
            self.ktlin =squares[self.id + 15].name + self.name
            self.ktlout = self.name + squares[self.id + 15].name
            self.ktrin = squares[self.id + 17].name + self.name
            self.ktrout = self.name + squares[self.id + 17].name
            self.kblin = squares[self.id-17].name + self.name
            self.kblout =  self.name + squares[self.id-17].name
            self.kbrin = squares[self.id-15].name + self.name
            self.kbrout = self.name + squares[self.id-15].name

    def gen_connects(self):
        if (self.name == "a1") :
            self.tlin = "0" #top left, continue ccw
            self.tlout = "0"
            self.midlin = "0"
            self.midlout = "0"
            self.blin = "0"
            self.blout = "0"
            self.midbin = "0"
            self.midbout = "0"
            self.brin = "0"
            self.brout = "0"
            self.midrin = squares[self.id+1].name + self.name
            self.midrout = self.name + squares[self.id+1].name
            self.trin = squares[self.id+9].name + self.name
            self.trout = self.name + squares[self.id + 9].name
            self.midtin = squares[self.id + 8].name + self.name
            self.midtout =  self.name + squares[self.id + 8].name
            self.kltin = "0"
            self.kltout = "0"
            self.klbin = "0"
            self.klbout = "0"
            self.krbin = "0"
            self.krbout = "0"
            self.krtin = squares[self.id + 10].name + self.name
            self.krtout = self.name + squares[self.id + 10].name
            self.ktlin ="0"
            self.ktlout = "0"
            self.ktrin = squares[self.id + 17].name + self.name
            self.ktrout = self.name + squares[self.id + 17].name
            self.kblin = "0"
            self.kblout =  "0"
            self.kbrin = "0"
            self.kbrout = "0"
        elif (self.name == "a8"):
            self.tlin = "0" #top left, continue ccw
            self.tlout = "0"
            self.midlin = "0"
            self.midlout = "0"
            self.blin = "0"
            self.blout = "0"
            self.midbin = squares[self.id-8].name + self.name
            self.midbout = self.name + squares[self.id-8].name
            self.brin = squares[self.id-7].name + self.name
            self.brout = self.name + squares[self.id-7].name
            self.midrin = squares[self.id+1].name + self.name
            self.midrout = self.name + squares[self.id+1].name
            self.trin = "0"
            self.trout = "0"
            self.midtin = "0"
            self.midtout =  "0"
            self.kltin = "0"
            self.kltout = "0"
            self.klbin = "0"
            self.klbout = "0"
            self.krbin = squares[self.id-10].name + self.name
            self.krbout = self.name + squares[self.id-10].name
            self.krtin = "0"
            self.krtout = "0"
            self.ktlin = "0"
            self.ktlout = "0"
            self.ktrin = "0"
            self.ktrout = "0"
            self.kblin = "0"
            self.kblout =  "0"
            self.kbrin = squares[self.id-15].name + self.name
            self.kbrout = self.name + squares[self.id-15].name
        elif (self.name == "h1"):
            self.tlin = squares[self.id+7].name + self.name #top left, continue ccw
            self.tlout = self.name + squares[self.id + 7].name
            self.midlin = squares[self.id-1].name + self.name
            self.midlout = self.name + squares[self.id-1].name
            self.blin = "0"
            self.blout = "0"
            self.midbin = "0"
            self.midbout = "0"
            self.brin = "0"
            self.brout = "0"
            self.midrin = "0"
            self.midrout = "0"
            self.trin = "0"
            self.trout = "0"
            self.midtin = squares[self.id + 8].name + self.name
            self.midtout =  self.name + squares[self.id + 8].name
            self.kltin = squares[self.id + 6].name + self.name
            self.kltout = self.name + squares[self.id+6].name
            self.klbin = "0"
            self.klbout = "0"
            self.krbin = "0"
            self.krbout = "0"
            self.krtin = "0"
            self.krtout = "0"
            self.ktlin =squares[self.id + 15].name + self.name
            self.ktlout = self.name + squares[self.id + 15].name
            self.ktrin = "0"
            self.ktrout = "0"
            self.kblin = "0"
            self.kblout =  "0"
            self.kbrin = "0"
            self.kbrout = "0"
        elif (self.name == "h8"):
            self.tlin = "0"
            self.tlout = "0"
            self.midlin = squares[self.id-1].name + self.name
            self.midlout = self.name + squares[self.id-1].name
            self.blin = squares[self.id-9].name + self.name
            self.blout = self.name + squares[self.id-9].name
            self.midbin = squares[self.id-8].name + self.name
            self.midbout = self.name + squares[self.id-8].name
            self.brin = "0"
            self.brout = "0"
            self.midrin = "0"
            self.midrout = "0"
            self.trin = "0"
            self.trout = "0"
            self.midtin = "0"
            self.midtout =  "0"
            self.kltin = "0"
            self.kltout = "0"
            self.klbin = squares[self.id-6].name + self.name
            self.klbout = self.name + squares[self.id-6].name
            self.krbin = "0"
            self.krbout = "0"
            self.krtin = "0"
            self.krtout = "0"
            self.ktlin ="0"
            self.ktlout = "0"
            self.ktrin = "0"
            self.ktrout = "0"
            self.kblin = squares[self.id-17].name + self.name
            self.kblout =  self.name + squares[self.id-17].name
            self.kbrin = "0"
            self.kbrout = "0"
        elif (self.name[0] == "a"):
            self.tlin = "0" #top left, continue ccw
            self.tlout = "0"
            self.midlin = "0"
            self.midlout = "0"
            self.blin = "0"
            self.blout = "0"
            self.midbin = squares[self.id-8].name + self.name
            self.midbout = self.name + squares[self.id-8].name
            self.brin = squares[self.id-7].name + self.name
            self.brout = self.name + squares[self.id-7].name
            self.midrin = squares[self.id+1].name + self.name
            self.midrout = self.name + squares[self.id+1].name
            self.trin = squares[self.id+9].name + self.name
            self.trout = self.name + squares[self.id + 9].name
            self.midtin = squares[self.id + 8].name + self.name
            self.midtout =  self.name + squares[self.id + 8].name
            self.kltin = "0"
            self.kltout = "0"
            self.klbin = "0"
            self.klbout = "0"
            self.krbin = squares[self.id-10].name + self.name
            self.krbout = self.name + squares[self.id-10].name
            self.krtin = squares[self.id + 10].name + self.name
            self.krtout = self.name + squares[self.id + 10].name
            self.ktlin = "0"
            self.ktlout = "0"
            if (self.name != "a7"):
                self.ktrin = squares[self.id + 17].name + self.name
                self.ktrout = self.name + squares[self.id + 17].name
            else:
                self.ktrin = "0"
                self.ktrout = "0"
            self.kblin = "0"
            self.kblout =  "0"
            if (self.name != "a7"):
                self.kbrin = squares[self.id - 15].name + self.name
                self.kbrout = self.name + squares[self.id - 15].name
            else:
                self.kbrin = "0"
                self.kbrout = "0"
        elif (self.name[0] == "h"):
            self.tlin = squares[self.id+7].name + self.name #top left, continue ccw
            self.tlout = self.name + squares[self.id + 7].name
            self.midlin = squares[self.id-1].name + self.name
            self.midlout = self.name + squares[self.id-1].name
            self.blin = squares[self.id-9].name + self.name
            self.blout = self.name + squares[self.id-9].name
            self.midbin = squares[self.id-8].name + self.name
            self.midbout = self.name + squares[self.id-8].name
            self.brin = "0"
            self.brout = "0"
            self.midrin = "0"
            self.midrout = "0"
            self.trin = "0"
            self.trout = "0"
            self.midtin = squares[self.id + 8].name + self.name
            self.midtout =  self.name + squares[self.id + 8].name
            self.kltin = squares[self.id + 6].name + self.name
            self.kltout = self.name + squares[self.id+6].name
            self.klbin = squares[self.id-6].name + self.name
            self.klbout = self.name + squares[self.id-6].name
            self.krbin = "0"
            self.krbout = "0"
            self.krtin = "0"
            self.krtout = "0"
            if(self.name != "h7"):
                self.ktlin =squares[self.id + 15].name + self.name
                self.ktlout = self.name + squares[self.id + 15].name
            else:
                self.ktlin = "0"
                self.ktlout = "0"
            self.ktrin = "0"
            self.ktrout = "0"
            if(self.name != "h8"):
                self.kblin =squares[self.id-17].name + self.name
                self.kblout = self.name + squares[self.id-17].name
            else:
                self.kblin = "0"
                self.kblout = "0"
            self.kbrin = "0"
            self.kbrout = "0"
        elif (self.name[1] == "1"):
            self.tlin = squares[self.id+7].name + self.name #top left, continue ccw
            self.tlout = self.name + squares[self.id + 7].name
            self.midlin = squares[self.id-1].name + self.name
            self.midlout = self.name + squares[self.id-1].name
            self.blin = "0"
            self.blout = "0"
            self.midbin = "0"
            self.midbout = "0"
            self.brin = "0"
            self.brout = "0"
            self.midrin = squares[self.id+1].name + self.name
            self.midrout = self.name + squares[self.id+1].name
            self.trin = squares[self.id+9].name + self.name
            self.trout = self.name + squares[self.id + 9].name
            self.midtin = squares[self.id + 8].name + self.name
            self.midtout =  self.name + squares[self.id + 8].name
            if(self.name != "b1"):
                self.kltin = squares[self.id + 6].name + self.name
                self.kltout = self.name + squares[self.id+6].name
            else:
                self.kltin = "0"
                self.kltout = "0"

            self.klbin = "0"
            self.klbout = "0"
            self.krbin = "0"
            self.krbout = "0"
            if(self.name != "g1"):
                self.krtin = squares[self.id + 10].name + self.name
                self.krtout = self.name + squares[self.id + 10].name
            else:
                self.krtin = "0"
                self.krtout = "0"

            self.ktlin =squares[self.id + 15].name + self.name
            self.ktlout = self.name + squares[self.id + 15].name
            self.ktrin = squares[self.id + 17].name + self.name
            self.ktrout = self.name + squares[self.id + 17].name
            self.kblin = "0"
            self.kblout =  "0"
            self.kbrin = "0"
            self.kbrout = "0"
        elif (self.name[1] == "8"):
            self.tlin = "0" #top left, continue ccw
            self.tlout = "0"
            self.midlin = squares[self.id-1].name + self.name
            self.midlout = self.name + squares[self.id-1].name
            self.blin = squares[self.id-9].name + self.name
            self.blout = self.name + squares[self.id-9].name
            self.midbin = squares[self.id-8].name + self.name
            self.midbout = self.name + squares[self.id-8].name
            self.brin = squares[self.id-7].name + self.name
            self.brout = self.name + squares[self.id-7].name
            self.midrin = squares[self.id+1].name + self.name
            self.midrout = self.name + squares[self.id+1].name
            self.trin = "0"
            self.trout = "0"
            self.midtin = "0"
            self.midtout =  "0"
            self.kltin = "0"
            self.kltout = "0"
            if(self.name != "b8"):
                self.klbin = squares[self.id-6].name + self.name
                self.klbout = self.name + squares[self.id-6].name
            else:
                self.klbin = "0"
                self.klbout = "0"
                
            if(self.name != "g8"):
                self.krbin = squares[self.id-10].name + self.name
                self.krbout = self.name + squares[self.id-10].name
            else:
                self.krbin = "0"
                self.krbout = "0"
                
            self.krtin = "0"
            self.krtout = "0"
            self.ktlin ="0"
            self.ktlout = "0"
            self.ktrin = "0"
            self.ktrout = "0"
            self.kblin = squares[self.id-17].name + self.name
            self.kblout =  self.name + squares[self.id-17].name
            self.kbrin = squares[self.id-15].name + self.name
            self.kbrout = self.name + squares[self.id-15].name
            print("ok")
        else:
            self.tlin = squares[self.id+7].name + self.name #top left, continue ccw
            self.tlout = self.name + squares[self.id + 7].name
            self.midlin = squares[self.id-1].name + self.name
            self.midlout = self.name + squares[self.id-1].name
            self.blin = squares[self.id-9].name + self.name
            self.blout = self.name + squares[self.id-9].name
            self.midbin = squares[self.id-8].name + self.name
            self.midbout = self.name + squares[self.id-8].name
            self.brin = squares[self.id-7].name + self.name
            self.brout = self.name + squares[self.id-7].name
            self.midrin = squares[self.id+1].name + self.name
            self.midrout = self.name + squares[self.id+1].name
            self.trin = squares[self.id+9].name + self.name
            self.trout = self.name + squares[self.id + 9].name
            self.midtin = squares[self.id + 8].name + self.name
            self.midtout =  self.name + squares[self.id + 8].name
            self.do_special_knights()
            #todo, if logic for the special knight squares


        self.in_connections[0] = self.tlin
        self.out_connections[0] = self.tlout
        self.in_connections[1] = self.midlin
        self.out_connections[1] = self.midlout
        self.in_connections[2] = self.blin
        self.out_connections[2] = self.blout
        self.in_connections[3] = self.midbin
        self.out_connections[3] = self.midbout
        self.in_connections[4] = self.brin
        self.out_connections[4] = self.brout
        self.in_connections[5] = self.midrin
        self.out_connections[5] = self.midrout
        self.in_connections[6] = self.trin
        self.out_connections[6] = self.trout
        self.in_connections[7] = self.midtin
        self.out_connections[7] = self.midtout
        self.in_connections[8] = self.kltin
        self.out_connections[8] = self.kltout
        self.in_connections[9] = self.klbin
        self.out_connections[9] = self.klbout
        self.in_connections[10] = self.krbin
        self.out_connections[10] = self.krbout
        self.in_connections[11] = self.krtin
        self.out_connections[11] = self.krtout
        self.in_connections[12] = self.tlin
        self.out_connections[12] = self.tlout
        self.in_connections[13] = self.trin
        self.out_connections[13] = self.trout
        self.in_connections[14] = self.blin
        self.out_connections[14] = self.blout
        self.in_connections[15] = self.brin
        self.out_connections[15] = self.brout


for i in range(0,64):
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
    fileo.write("\n\nsquare " + s.name + "(\n          .clock(clk), \n          .init(init), \n          .occupied(" + s.name + "_occ), \n          .square_id(")
    fileo.write("5'd" + s.name + ", \n          .piece_type_calc(piece_type_calc), " + "\n          .occupying_piece(" + s.name)
    fileo.write("_occupying_piece), " + s.connection_string + ", \n          .movebit(move_wires[" + s.name + "])")



fileo.close()
