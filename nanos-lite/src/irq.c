#include <common.h>


/* 为了代码提示 */
// enum {
//   EVENT_NULL = 0,
//   EVENT_YIELD, EVENT_SYSCALL, EVENT_PAGEFAULT, EVENT_ERROR,
//   EVENT_IRQ_TIMER, EVENT_IRQ_IODEV,
// };

static Context* do_event(Event e, Context* c) {
  switch (e.event) {
  case EVENT_YIELD: printf("do_event:EVENT_YIELD\n");  c->mepc += 4;break;
  default: panic("Unhandled event ID = %d", e.event);
  }
  return c;
}

void init_irq(void) {
  Log("Initializing interrupt/exception handler...");
  cte_init(do_event);
}
