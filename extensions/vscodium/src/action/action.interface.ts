import { ContainerService } from '../container/container.service';

export interface Action {
  name: string;
  execute(container: ContainerService, ...args: any[]): void;
}
