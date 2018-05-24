module reg32(
input [31:0] dIn,
input [3:0] byteenable,
input clock,
input reset_n,
output dOut
);

reg [31:0] data;

//Synchronous logic
always@(posedge clock) 
begin
	if (~reset_n)
	begin
		data <= 4'b0000;
	end
	else if(byteenable == 4'b1111)
	begin
		data <= dIn;
	end
	else if (byteenable == 4'b0011)
	begin
		data[15:0] <= dIn[7:0];
	end
	else if (byteenable == 4'b1100)
	begin
		data[31:16] <= dIn[31:16];
	end
	else if (byteenable == 4'b0001)
	begin
		data[7:0] <= dIn[7:0];
	end
	else if (byteenable == 4'b0010)
	begin
		data[15:8] <= dIn[15:8];
	end
	else if (byteenable == 4'b0100)
	begin
		data[23:16] <= dIn[23:16];
	end
	else if (byteenable == 4'b1000)
	begin
		//data[31:24] <= dIn[31:24];
	end
end

endmodule