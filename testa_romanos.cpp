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
    REQUIRE( romanos_para_decimal("XV") == 15 );
    REQUIRE( romanos_para_decimal("XX") == 20 );
    REQUIRE( romanos_para_decimal("XVII") == 17 );
}

TEST_CASE( "Numeros romanos - Subtração de digitos", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("IV") == 4 );
    REQUIRE( romanos_para_decimal("XIV") == 14 );
    REQUIRE( romanos_para_decimal("CDXLIV") == 444);
    REQUIRE( romanos_para_decimal("DCIX") == 609);
    REQUIRE( romanos_para_decimal("CCCXCIX") == 399);
    REQUIRE( romanos_para_decimal("DXCVIII") == 598);
    REQUIRE( romanos_para_decimal("DCXXXVIII") == 638);
}


TEST_CASE( "Numeros romanos - Testando invalidos", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("-23") == -1 );
    REQUIRE( romanos_para_decimal("-IVV") == -1 );
    REQUIRE( romanos_para_decimal("IIIIV") == -1);
    REQUIRE( romanos_para_decimal("----") == -1);
    REQUIRE( romanos_para_decimal("ivxx") == -1);
}
