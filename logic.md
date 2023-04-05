# Programming Logic

> For each behaviour, create the mermaid flowchart. Start each flowchart with a Heading naming the functionality. Delete this comment prior to submission.

## force doorbell

```mermaid
flowchart TD
    start([doorbell])
    getButtonStatus(Get Button Status)
    checkButton{has button been pressed}
    soundBell(play sound)
    finish([end])


    start-->getButtonStatus-->checkButton
    checkButton-->|yes|soundBell
    checkButton-->|no|finish
    soundBell-->finish

```