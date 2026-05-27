import { type RowDataPacket } from "mysql2/promise";

// DATABASE COLUMNS

export interface IReis extends RowDataPacket {
  // extends = inheritance (: in cs)
  id: number;
  bestemming: string;
  jaar: number;
  kosten: IKost[];
}

export interface IKost extends RowDataPacket {
  uitgave: string;
  prijs: number;
}
