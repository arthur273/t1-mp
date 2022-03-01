#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "romanos.hpp"

TEST_CASE( "Numeros romanos - Conversão de digitos ", "[romanos]" ) {
    REQUIRE( converte_digito('I') == 1 );
    REQUIRE( converte_digito('V') == 5 );
    REQUIRE( converte_digito('X') == 10 );
    REQUIRE( converte_digito('L') == 50 );
    REQUIRE( converte_digito('C') == 100 );
    REQUIRE( converte_digito('D') == 500 );
    REQUIRE( converte_digito('M') == 1000 );
}

TEST_CASE( "Numeros romanos - Soma de digitos", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("II") == 2 );
    REQUIRE( romanos_para_decimal("MM") == 2000 );
    REQUIRE( romanos_para_decimal("XV") == 15 );
    REQUIRE( romanos_para_decimal("XX") == 20 );
    REQUIRE( romanos_para_decimal("XVII") == 17 );
    REQUIRE( romanos_para_decimal("MMDCCCI") == 2801 );
    REQUIRE( romanos_para_decimal("CCCX") == 310 );
    REQUIRE( romanos_para_decimal("MDCCLXV") == 1765 );
}
TEST_CASE( "Numeros romanos - Subtração de digitos", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("IV") == 4 );
    REQUIRE( romanos_para_decimal("XIV") == 14 );
    REQUIRE( romanos_para_decimal("CDXLIV") == 444);
    REQUIRE( romanos_para_decimal("DCIX") == 609);
    REQUIRE( romanos_para_decimal("CCCXCIX") == 399);
    REQUIRE( romanos_para_decimal("DXCVIII") == 598);
    REQUIRE( romanos_para_decimal("DCXXXVIII") == 638);
    REQUIRE( romanos_para_decimal("CXLVII") == 147);
    REQUIRE( romanos_para_decimal("MMCMXCIX") == 2999);
    REQUIRE( romanos_para_decimal("MMCMLXXV") == 2975);
    REQUIRE( romanos_para_decimal("MMCXXIX") == 2129);
    REQUIRE( romanos_para_decimal("MCDXXIX") == 1429);
}


TEST_CASE( "Numeros romanos - Avaliação de invalidos", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("-23") == -1 );
    REQUIRE( romanos_para_decimal("-IVV") == -1 );
    REQUIRE( romanos_para_decimal("IIIIV") == -1);
    REQUIRE( romanos_para_decimal("----") == -1);
    REQUIRE( romanos_para_decimal("ivxx") == -1);
    REQUIRE( romanos_para_decimal("VX") == -1);
    REQUIRE( romanos_para_decimal("XXXX") == -1);
    REQUIRE( romanos_para_decimal("VIX") == -1);
    REQUIRE( romanos_para_decimal("XXL") == -1);
    REQUIRE( romanos_para_decimal("VV") == -1);
    REQUIRE( romanos_para_decimal("XXVVIX") == -1);
    REQUIRE( romanos_para_decimal("LL") == -1);
    REQUIRE( romanos_para_decimal("MMLLMM") == -1);
    REQUIRE( romanos_para_decimal("XXIM") == -1);
    REQUIRE( romanos_para_decimal("XML") == -1);
}
