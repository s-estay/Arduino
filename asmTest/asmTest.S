#include "avr/io.h"

//
// Adjusted wiring, which allows us to suppress some shift
// instructions
//
// Led 1 = pin 8
// Led 2 = pin 9
// Led 3 = pin 2
// Led 4 = pin 3
// Led 5 = pin 4
// Led 6 = pin 5
// Led 7 = pin 6
// Led 8 = pin 7
//

#define yl r28
#define yh r29

// const long delay = 100;
#define delay 1000 // ms

.global setup
setup:
  in r25, _SFR_IO_ADDR(DDRD)
  ori r25, 0xFC
  out _SFR_IO_ADDR(DDRD), r25
  
  in r25, _SFR_IO_ADDR(DDRB)
  ori r25, 0x03
  out _SFR_IO_ADDR(DDRB), r25

  ret

.global loop
loop:

  push yl
  push yh

  call millis   ; call millis(): 4-byte return value in r25...r22
  
  // Use Y as a pointer to fetch the next time to switch the LED
  ldi yl, lo8(nextSwitchAfterMillis) 
  ldi yh, hi8(nextSwitchAfterMillis)
  
  ld r18, y
  ldd r19, y+1
  ldd r20, y+2
  ldd r21, y+3
  
  ldd r17, y+4
  ldd r16, y+5
  
  // Compare nextSwitchAfterMillis with value returned by millis()
  cp r22, r18
  cpc r23, r19
  cpc r24, r20
  cpc r25, r21
  
  brcs tooEarly ; carry is clear if r18...r21(nextSwitchAfterMillis) < r22...r25(millis())

  // Rotate left & right; bit travels up then down through r17 and r16
  // Carry is already clear because brcs was not taken, so no need for CLC
  rol r17
  sbrc r16,0
  ori r17,1
  ror r16

  // Update the memory storage with the new rotated values
  std y+4, r17
  std y+5, r16

  // Combine left and right shifter
  or r17, r16
  
  // 6 high bits of port D
  mov r16, r17
  andi r16, 0xFC
  out _SFR_IO_ADDR(PORTD), r16
 
  // 2 low bits of port B
  andi r17,0x03
  out _SFR_IO_ADDR(PORTB), r17
  
  // Add delay (subtract negative delay because there is no addi/adci)
  // to result of call to millis()
  subi r22, lo8(-delay)
  sbci r23, hi8(-delay)
  sbci r24, hlo8(-delay)
  sbci r25, hhi8(-delay)
      
  st y, r22
  std y+1, r23
  std y+2, r24
  std y+3, r25
  
tooEarly: 
  pop yh
  pop yl
  
  ret

.data 

nextSwitchAfterMillis:
.long 0

shifters:
.byte 1
.byte 0x80
.byte 0
