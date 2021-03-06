module MUX_2_5bit(
    input logic [4:0] a, b,
    input logic select,
    output logic [4:0] out
);

    always_comb begin
        case(select)
        0:  out = a;
        1:  out = b;
        endcase
    end

endmodule
