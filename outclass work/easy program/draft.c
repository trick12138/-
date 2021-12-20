/* while(pFrountMove != NULL)
            {
                if (pFrountMove->data.hash == dataHashPos)    //hash冲突
                {
                    struct skipTable *rFrountMove = pFrountMove;
                    if (rFrountMove->Rnext == NULL)     //若为空
                    {
                        rFrountMove->Rnext = newSkipNode;
                        return;
                    }
                    else    //若不为空则找
                    {
                        struct skipTable *rMove = rFrountMove->Rnext;
                        while(rMove != NULL && newSkipNode->data.hash > rMove->data.hash)
                        {
                            rMove = rMove->Rnext;
                            rFrountMove = rFrountMove->Rnext;
                        }
                        rFrountMove->Rnext = newSkipNode;
                        newSkipNode->Rnext = rMove;
                        return;
                    }
                }
                if (dataHashPos < pFrountMove->data.hash)
                {
                    pFrountMove->next = newSkipNode;
                    newSkipNode->next = pMove;
                    return;
                }
                pFrountMove = pFrountMove->next;
                pMove = pMove->next;
            }
            pFrountMove->next = newSkipNode;  //最后没找到 */
#define Line 108