//high low register block, with clocked input
//If WriteEnable is HIGH, write data from 32 bit input bus into the high/low register
//Data is read from register every clock cycle
//If Control_High is HIGH, read/write to HIGH register,
//if Control_High is LOW, read/write to LOW register

//sidenote: check if case inside case loop is legal in verilog

module high_low_registers(

    input logic clk,
    input logic reset,
    input logic ctrl_hi, WrEn,
    input logic [31:0] input_hi_lo,
    output logic [31:0] out

);

    logic [31:0] reg_hi, reg_lo;

    always_ff @(posedge clk) begin
    case(reset)
      0:  case(WrEn)

        0:  case(ctrl_hi)
            0: out <= reg_lo ;
            1: out <= reg_hi ;
            endcase

        1:  case(ctrl_hi)
            0:  begin
                out <= reg_lo ;
                reg_lo <= input_hi_lo ;
                end
            1:  begin
                out <= reg_hi ;
                reg_hi <= input_hi_lo ;
                end
            endcase
        endcase
      1:  begin
          reg_lo <= 32'h00000000;
          reg_hi <= 32'h00000000;
          end
          endcase
    end

endmodule
